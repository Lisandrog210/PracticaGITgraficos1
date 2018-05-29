using namespace std;
#include <iostream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

int main(int argc, char **argv){

   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_BITMAP  *image, *resizeImage   = NULL;

   if(!al_init()) {
      al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   if(!al_init_image_addon()) {
      al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   display = al_create_display(800,600);

   if(!display) {
      al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   image = al_load_bitmap("imagen.jpg");
   resizeImage = al_create_bitmap(50, 50);
   
   //stretch_blit(image, resizeImage, 0, 0, image->w, image->h, 0, 0, resizeImage->w, resizeImage->h);
   //al_destroy_bitmap(image);


   if(!image) {
      al_show_native_message_box(display, "Error", "Error", "Failed to load image!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(display);
      return 0;
   }

   al_draw_bitmap(image,50,50,0);
   
   al_flip_display();
   al_rest(2);
   cin.get();
   al_destroy_display(display);
   al_destroy_bitmap(image);

   return 0;
}