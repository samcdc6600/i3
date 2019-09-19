--- i3bar/src/xcb.c.orig	2019-08-03 13:14:38 UTC
+++ i3bar/src/xcb.c
@@ -39,6 +39,9 @@
 /** This is the equivalent of XC_left_ptr. I’m not sure why xcb doesn’t have a
  * constant for that. */
 #define XCB_CURSOR_LEFT_PTR 68
+/* Start and stop binary clock. */
+#define START_BIN_CLOCK "binClock &"
+#define KILL_BIN_CLOCK "pkill -9 binClock"
 
 /* We save the atoms in an easy to access array, indexed by an enum */
 enum {
@@ -335,6 +338,7 @@ static void draw_statusline(i3_output *output, uint32_
  *
  */
 static void hide_bars(void) {
+  system(KILL_BIN_BLOCK);
     if ((config.hide_on_modifier == M_DOCK) || (config.hidden_state == S_SHOW && config.hide_on_modifier == M_HIDE)) {
         return;
     }
@@ -354,6 +358,7 @@ static void hide_bars(void) {
  *
  */
 static void unhide_bars(void) {
+  system(START_BIN_CLOCK);
     if (config.hide_on_modifier != M_HIDE) {
         return;
     }
