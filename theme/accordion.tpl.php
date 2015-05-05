<?php
/**
* @file
* Default output for a Accordion object.
*/

?>
<div id="<?php print $settings['attributes']['id']; ?>">
  <?php foreach ($items as $key => $item): ?>
    <?php print $item['item']['entity']; ?>
  <?php endforeach; ?>
</div>
