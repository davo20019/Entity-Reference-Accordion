<?php
/**
 *
 * @file
 * Theming functions for the accordion_entityreference module.
 *
 */

/**
 * Template process handler for 'accordion_entityreference'.
 */
function template_process_accordion_entityreference(&$vars) {

  $attributes       = array();
  $accordion_id     = &drupal_static('accordion_id', 0);
  $attributes['id'] = 'accordion-' . ++$accordion_id;

  $settings =& $vars['settings'];
  $settings['attributes'] = $attributes;

  accordion_add($settings['attributes']['id'], $settings['header'], $settings['content']);

  $vars['accordion'] += array(
    '#theme' => 'accordion',
    '#items' => array(),
    '#settings' => $settings,
  );
  foreach (element_children($vars['entities']) as $delta) {
    $item = &$vars['entities'][$delta]['element'];
    $item['entity'] = drupal_render($item['entity']);
    $item['#settings'] = $vars['settings'];

    $vars['accordion']['#items'][$delta] = array(
      'item' => $item
    );
  }
}

/**
 * Default theme implementation for 'accordion_entityreference'.
 */
function theme_accordion_entityreference($vars) {
  $output = '';
  $output .= drupal_render($vars['accordion']);
  return $output;
}

/**
 * Default theme implementation for 'accordion_entitylist'.
 *
 * @see theme_accordion_list().
 */
function theme_accordion_entitylist($vars) {

  // Reference configuration variables
  $items = &$vars['items'];
  $attributes = &$vars['settings']['attributes'];
  $type = &$vars['settings']['type'];

  $output = array();

  // Build the list
  if (!empty($items)) {
    $output['items'] = array(
      '#prefix' => '<' . $type . drupal_attributes($attributes) . '>',
      '#suffix' => '</' . $type . '>',
    );
    foreach ($items as $delta => $item) {
      $output['items'][$delta] = array(
        '#theme' => 'accordion_list_entity',
        '#item' => $item['element'],
      );
    }
  }

  return drupal_render($output);
}

/**
 * Default theme implementation for 'accordion_list_entity'.
 *
 * @see theme_accordion_list_item().
 */
function theme_accordion_list_entity($vars) {
  return '<li' . drupal_attributes($vars['settings']['attributes']) . '>' . $vars['item']['entity'] . $vars['caption'] . "</li>\n";
}
