/* { dg-lto-do link } */
/* { dg-lto-options {{-O0 -fwhopr}} } */
/* { dg-extra-ld-options {-shared -O2 -fwhopr} } */

int main(int argc, char **argv) {
  return 0;
}
