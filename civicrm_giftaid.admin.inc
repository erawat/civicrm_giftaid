<?php

/**
* Form function, called by drupal_get_form()
* in giftaid_menu().
*/
function giftaid_form($form, &$form_state) {
  $form['giftaid_value'] = array(
    '#type' => 'textfield',
    '#title' => t('Gift Aid Rate'),
    '#default_value' => variable_get('giftaid_value'),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t('The percentage of gift aid that system used to calculate.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

function giftaid_form_validate($form, &$form_state){
  $giftaid_value = $form_state['values']['giftaid_value'];
  if (!is_numeric($giftaid_value)){
    form_set_error('giftaid_value', t('You must enter an integer for the maximum number of posts to display.'));
  }
  else if ($giftaid_value <= 0){
    form_set_error('giftaid_value', t('Maximum number of posts to display must be positive.'));      
  }
}


?>


