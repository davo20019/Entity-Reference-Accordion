(function($) {
  Drupal.behaviors.accordion_entityreference = {
    attach: function (context, settings) {

      if ($.type(settings.accordion_entityreference) !== 'undefined') {
        var accordion = settings.accordion_entityreference;
        $.each(accordion, function(index, element) {
          //Initialization
          var id = element.accordion_id;
          var h  = element.accordion_header;
          var content = element.accordion_content;
          var htmlId = element.htmlId;
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

        });
      }
    }
 }
}(jQuery));
