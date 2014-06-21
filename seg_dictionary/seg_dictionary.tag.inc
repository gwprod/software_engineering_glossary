<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function seg_dictionary_tag_field_info()
{
  
}

function seg_dictionary_tag_list_tags_as_table($dictionary) {
  $result = db_query('select tag_id, tag_name, tag_description from seg_dictionary_tags where dictionary_id =:dictionary_id', array(
    'dictionary_id' => $dictionary->dictionary_id
  ));
  $rows = array();
  foreach ($result as $tag) {
    $rows[$tag->tag_id] = array(
      'name' => $tag->tag_name,
      'description' => $tag->tag_description
    );
  }
  $header = array(t('Tag Name'), t('Tag Description'));
  $content['table'] = array(
    '#theme' => 'table',
    '#rows' => $rows,
    '#empty' => t('No Tags for this dictionary'),
    '#attributes' => array(),
    '#header' => $header
  );
  return $content;
}

function seg_dictionary_tag_list_tags($dictionary) {
  $result = db_query('select tag_id, tag_name from seg_dictionary_tags where dictionary_id =:dictionary_id', array(
    'dictionary_id' => $dictionary->dictionary_id
  ));
  $tags = array();
  foreach ($result as $tag) {
    $tags[$tag->tag_id] = $tag->tag_name;
  }
  return $tags;
}

function seg_dictionary_tag_form($form, &$form_state, $dictionary) {
  if (isset($form_state['values']['dictionary_id'])) {
    global $user;
    $dictionary = seg_dictionary_load($form_state['values']['dictionary_id']);
    $record = array(
      'uid' => $user->uid,
      'tag_name' => $form_state['values']['tag_name'],
      'tag_description' => $form_state['values']['tag_description'],
      'dictionary_id' => $dictionary->dictionary_id
    );

    drupal_write_record('seg_dictionary_tags', $record);
  }
  //$tags = seg_dictionary_tag_list_tags($dictionary);
  $form['dictionary_id'] = array(
    '#type' => 'hidden',
    '#value' => $dictionary->dictionary_id
  );
  $form['tag_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Tag Name'),
    '#required' => TRUE
  );
  $form['tag_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Tag Description'),
    '#required' => TRUE
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create Tag')
  );
  $form['tag_list'] = array(
    '#markup' => drupal_render(seg_dictionary_tag_list_tags_as_table($dictionary))
  );
  return $form;
}

function seg_dictionary_tag_form_submit($form, &$form_state) {

  $form_state['rebuild'] = true;
}
