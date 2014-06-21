<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Override hook_activity_info to define an activity
 */
function hook_seg_activity_info()
{
  $activity['[activity_name]'] = array(
    'title' => t('[activity_name]'),
    'bundle' => '[bundle_type]',
    'module' => '[module_name]',
    'form callback' => '[module_name]_seg_activity_form',
    'submit callback' => '[module_name]_seg_activity_form_submit',
    'formatter callback' => '[module_name]_seg_activity_formatter'
  );
  return $activity;
}

?>
