<?php

/*
 * Default server and index for fuzzysearchService.
 */

$name = st('Default fuzzysearch server');
$values = array(
  'name' => $name,
  'machine_name' => preg_replace('/[^a-z0-9]+/', '_', drupal_strtolower($name)),
  'description' => st('An automatically created Fuzzy Search server.'),
  'class' => 'fuzzysearch_service',
  'options' => array (
    'database' => 'default:default',
    'min_chars' => '3',
  ),
  'enabled' => '1',
);

if ($id = search_api_server_insert ($values)) {
  drupal_set_message(st('Fuzzy Search default server created. !edit this server.', array('!edit' => l(st('Edit'), 'admin/config/search/search_api/server/default_fuzzysearch_server'))));
}
else {
  drupal_set_message(st('Fuzzy Search default server could not be created.'), 'warning');  
}

$name = st('Default fuzzysearch index');
$values = array(
'name' => $name,
'machine_name' => preg_replace('/[^a-z0-9]+/', '_', drupal_strtolower($name)),
'description' => 'Automatically created Fuzzy Search Index.',
'server' => 'default_fuzzysearch_server',
'entity_type' => 'node',
'options' => array (
  'cron_limit' => '50',
  'fields' => 
  array (
    'search_api_language' => array (
      'name' => 'Item language',
      'indexed' => 1,
      'type' => 'string',
      'boost' => '1.0',
    ),
    'search_api_viewed' => array (
      'name' => 'Entity HTML output',
      'indexed' => 1,
      'type' => 'text',
      'boost' => '1.0',
    ),
    'nid' => array (
      'name' => 'Node ID',
      'indexed' => 0,
      'type' => 'integer',
      'boost' => '1.0',
    ),
    'vid' => array (
      'name' => 'Revision ID',
      'indexed' => 0,
      'type' => 'integer',
      'boost' => '1.0',
    ),
    'is_new' => array (
      'name' => 'Is new',
      'indexed' => 0,
      'type' => 'boolean',
      'boost' => '1.0',
    ),
    'type' => array (
      'name' => 'Content type',
      'indexed' => 0,
      'type' => 'string',
      'boost' => '1.0',
    ),
    'title' => array (
      'name' => 'Title',
      'indexed' => 1,
      'type' => 'text',
      'boost' => '5.0',
    ),
    'language' => array (
      'name' => 'Language',
      'indexed' => 0,
      'type' => 'string',
      'boost' => '1.0',
    ),
    'url' => array (
      'name' => 'URL',
      'indexed' => 0,
      'type' => 'uri',
      'boost' => '1.0',
    ),
    'edit_url' => array (
      'name' => 'Edit URL',
      'indexed' => 0,
      'type' => 'uri',
      'boost' => '1.0',
    ),
    'status' => array (
      'name' => 'Published',
      'indexed' => 0,
      'type' => 'boolean',
      'boost' => '1.0',
    ),
    'promote' => array (
      'name' => 'Promoted to frontpage',
      'indexed' => 0,
      'type' => 'boolean',
      'boost' => '1.0',
    ),
    'sticky' => array (
      'name' => 'Sticky in lists',
      'indexed' => 0,
      'type' => 'boolean',
      'boost' => '1.0',
    ),
    'created' => array (
      'name' => 'Date created',
      'indexed' => 0,
      'type' => 'date',
      'boost' => '1.0',
    ),
    'changed' =>  array (
      'name' => 'Date changed',
      'indexed' => 0,
      'type' => 'date',
      'boost' => '1.0',
    ),
    'author' => array (
      'name' => 'Author',
      'indexed' => 0,
      'type' => 'integer',
      'entity_type' => 'user',
      'boost' => '1.0',
    ),
    'source' => array (
      'name' => 'Translation source node',
      'indexed' => 0,
      'type' => 'integer',
      'entity_type' => 'node',
      'boost' => '1.0',
    ),
    'log' => array (
      'name' => 'Revision log message',
      'indexed' => 0,
      'type' => 'text',
      'boost' => '1.0',
    ),
    'revision' => array (
      'name' => 'Creates revision',
      'indexed' => 0,
      'type' => 'boolean',
      'boost' => '1.0',
    ),
    'comment' => array (
      'name' => 'Comments allowed',
      'indexed' => 0,
      'type' => 'integer',
      'boost' => '1.0',
    ),
    'comment_count' => array (
      'name' => 'Comment count',
      'indexed' => 0,
      'type' => 'integer',
      'boost' => '1.0',
    ),
    'comment_count_new' => array (
      'name' => 'New comment count',
      'indexed' => 0,
      'type' => 'integer',
      'boost' => '1.0',
    ),
    'field_tags' => array (
      'name' => 'Tags',
      'indexed' => 0,
      'type' => 'list<integer>',
      'entity_type' => 'taxonomy_term',
      'boost' => '1.0',
    ),
  ),
  'data_alter_callbacks' => array (
    'search_api_alter_bundle_filter' => array (
      'status' => 0,
      'weight' => '0',
      'settings' => array (
        'default' => '1',
        'bundles' => array (
        ),
      ),
    ),
    'search_api_alter_add_viewed_entity' => array (
      'status' => 1,
      'weight' => '0',
      'settings' => array (
        'mode' => 'full',
      ),
    ),
    'search_api_alter_add_aggregation' => array (
      'status' => 0,
      'weight' => '0',
      'settings' => NULL,
    ),
    'search_api_alter_add_url' => array (
      'status' => 0,
      'weight' => '0',
      'settings' => array (
      ),
    ),
  ),
  'processors' => array (
    'search_api_case_ignore' => array (
      'status' => 1,
      'weight' => '-50',
      'settings' => array (
        'strings' => 0,
      ),
    ),
    'search_api_html_filter' => array (
      'status' => 1,
      'weight' => '-49',
      'settings' => array (
        'title' => 0,
        'alt' => 1,
        'tags' => 'h1 = 5
          h2 = 3
          h3 = 2
          strong = 2
          b = 2
          em = 1.5
          u = 1.5',
      ),
    ),
    'search_api_tokenizer' => array (
      'status' => 1,
      'weight' => '-48',
      'settings' => array (
        'spaces' => '[^\\p{L}\\p{N}]',
        'ignorable' => '[-]',
      ),
    ),
    'fuzzysearch_search' => array (
      'status' => 1,
      'weight' => '-47',
      'settings' => array (
        'ngram_length' => '3',
        'missing_letters' => '5',
        'extra_letters' => '5',
        'completeness' => '40',
        'sort_score' => 0,
      ),
    ),
    'fuzzysearch_excerpt' => array (
      'status' => 1,
      'weight' => '-46',
      'settings' => array (
        'debug_score' => 0,
        'excerpt_length' => '200',
        'max_result_length' => '400',
        'spelling' => '30',
      ),
    ),
  ),
),
'enabled' => '1',
'read_only' => '0',
);

if ($id = search_api_index_insert ($values)) {
  drupal_set_message(st('Fuzzy Search default index created. !edit this index.', array('!edit' => l(st('Edit'), 'admin/config/search/search_api/index/default_fuzzysearch_index/edit'))));
}
else {
  drupal_set_message(st('Fuzzy Search default index could not be created.'), 'warning');  
}