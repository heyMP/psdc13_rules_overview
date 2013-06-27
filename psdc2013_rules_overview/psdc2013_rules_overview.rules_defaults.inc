<?php
/**
 * @file
 * psdc2013_rules_overview.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function psdc2013_rules_overview_default_rules_configuration() {
  $items = array();
  $items['rules_feature_article_validation'] = entity_import('rules_config', '{ "rules_feature_article_validation" : {
      "LABEL" : "Feature Article Validation",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "rules_conditional" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "article" : "article" } }
          }
        },
        { "NOT data_is_empty" : { "data" : [ "node:field-feautred" ] } }
      ],
      "DO" : [
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is_empty" : { "data" : [ "node:field-image" ] } },
              "DO" : [
                { "data_set" : { "data" : [ "node:field-feautred" ], "value" : 0 } },
                { "drupal_message" : { "message" : "For an article to be featured, you must provide an image." } }
              ]
            },
            { "ELSE" : [ { "drupal_message" : { "message" : "Hey Thank you so much!!!" } } ] }
          ]
        }
      ]
    }
  }');
  return $items;
}
