/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


(function($) {


    Drupal.behaviors.dragAndDrop = {
        attach: function(context, settings) {


            //console.log('attaching...');
            jQuery(".jumble_space").droppable({
                tolerance: "intersect",
                activeClass: "drop-hover",
                hoverClass: "hovering",
                drop: function(event, ui) {
                    
                    jQuery(ui.draggable).detach().css({top: -29,left: -19}).appendTo(this);
                }

            });
            jQuery(".jumble_tile").draggable({
                revert: "invalid"
            });



        }
    }
})(jQuery);


var draggable = new Drupal.ajax("#coordinator_list", jQuery("#coordinator_list"), {
    url: '',
    event: 'click'
});