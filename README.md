# Fuzzy Search

This module provides a fuzzy matching search engine for entities using the
`search_api` module. Entities are indexed when the site's cron job is run.  See
the index settings for options.

Fuzzy matching is implemented by using ngrams.  Each word is split
into 3 (default) letter lengths, so 'apple' gets indexed with 3 smaller strings
'app', 'ppl', 'ple'.  The effect of this is that as long as your search matches
X percentage (administerable in the admin settings) of the word the entity will
be pulled up in the results.

## Dependencies

- Search API

## Installation and Usage

- Install this module using the [official Backdrop CMS instructions](https://backdropcms.org/guide/modules)
- Usage instructions can be [viewed and edited in the Wiki](https://github.com/backdrop-contrib/fuzzysearch/wiki).
- To uninstall completely you must first delete any search pages and indexes.
  Then uninstall the module normally. Any servers using fuzzysearch will be
  deleted automatically.

## Configuration

  - A default search API server and index will be created when you install
    the fuzzysearch module. You can configure its settings in your Backdrop
    administration back-end at
    `Configuration > Search and metadata > Search API`.
  - The index will need to be disabled before you can edit the settings.
  - You will need to install search_api_page or views to create the search form
    and results page.
  - Access permissions for searching are controlled by search_api_page and
    views. Be sure only to index public content.
  - Run cron until your site is 100% indexed.
  - Consider using the search api stopwords processor and a stopwords file to
    keep common words from bloating your index.
  - Set up a regular cron job to keep your site fully indexed.

## Issues

 - Bugs and Feature requests should be reported in the [Issue Queue](https://github.com/backdrop-contrib/fuzzysearch/issues).

## Current Maintainers

 - [Laryn Kragt Bakker](https://github.com/laryn)
 - Seeking co-maintainers

## Credits

 - Ported to Backdrop CMS by [Laryn Kragt Bakker](https://github.com/laryn).
 - Created for Drupal by [Blake Lucchesi](https://www.drupal.org/u/blakelucchesi)
 - Maintainers on drupal.org include [Aaron Wolfe](https://www.drupal.org/u/awolfey),
   [Andreas W. Wylach](https://www.drupal.org/u/awwylach),
   [jagadeesh ramu javvadi](https://www.drupal.org/u/jagadeeshramuj),
   [Mario Steinitz](https://www.drupal.org/u/mario-steinitz),
   [Albert Volkman](https://www.drupal.org/u/albert-volkman), and
   [Robert Douglass](https://www.drupal.org/u/robertdouglass).

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

