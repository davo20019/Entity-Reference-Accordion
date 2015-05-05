<?php
/*
* Function to display windows modal with data ajax
 */
function get_info($js = NULL, $entityId) {
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();
  if ($entityId == NULL) {
    // You can customize the string below, or use a drupal_goto() to
    // send the user to a custom error page.
    return t('No node id was sent. Error.');
  }
  if ($js) {
    // Required includes for ctools to work:
    ctools_include('modal');
    ctools_include('ajax');
  }
  // Load  content entity plans : Product Tigo
  $aids[] = $entityId;
  $plan = entity_load('productos_tigo', $aids);
  $plan = $plan[$entityId]->field_products_plans_terms['und'][0]['value'];
  return ctools_modal_render(t("Terms and Conditions"), $plan) ;
}
