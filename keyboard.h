#ifndef KEYBOARD_H
#define KEYBOARD_H


enum Key {
    KEY_1 = 0,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_0,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_STAR,
    KEY_LATTER,
    KEY_NONE
};



void keyboard_init(void);
enum Key keyboard_read_key(void);



#endif // KEYBOARD_H
