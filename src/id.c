#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"
#include "id.h"


#define MY_UUID { 0x76, 0x9D, 0xC3, 0x51, 0xE1, 0x08, 0x4E, 0xBA, 0x98, 0xE2, 0x2F, 0xDB, 0xC8, 0x22, 0xCD, 0xD6 }
PBL_APP_INFO(MY_UUID,
             "Identification", "wereb.us",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_WATCH_FACE);

Window window;
TextLayer text_layer;


void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Contact Info");
  window_stack_push(&window, true /* Animated */);

  text_layer_init(&text_layer, window.layer.frame);
  text_layer_set_text(&text_layer, MYID);
  text_layer_set_text_alignment(&text_layer, GTextAlignmentCenter);
  layer_add_child(&window.layer, &text_layer.layer);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
