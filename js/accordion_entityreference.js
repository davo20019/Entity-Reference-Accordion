(function($) {
  Drupal.behaviors.accordion_entityreference = {
    attach: function (context, settings) {

      if ($.type(settings.accordion_entityreference) !== 'undefined' &&
          $.type(settings.accordion_entityreference.accordion_id) !== 'undefined') {

        //Initialization
        var id = settings.accordion_entityreference.accordion_id;
        var h  = settings.accordion_entityreference.accordion_header;
        var content = settings.accordion_entityreference.accordion_content;
        var htmlId = settings.accordion_entityreference.htmlId;
        var tabActive = false;
        var panel = false;
        var hash = false;


        // //Define tab active
        if (htmlId != undefined) {
          hash = $(htmlId).parents(content).attr('aria-labelledby');
        }

        //Define accordion
        $("#"+id).accordion({
          collapsible: true,
          active: tabActive,
          header: h
        });

        //if exist defined header
        if (hash != false && hash != undefined) {

          //Open the accordion for hash
          $('#'+hash).trigger( "click" );
        }
      }
    }
 }
}(jQuery));
