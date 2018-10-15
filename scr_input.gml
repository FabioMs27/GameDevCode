//Input

key_up = -max(keyboard_check(vk_up),keyboard_check(ord('W')),0);
key_down = max(keyboard_check(vk_down),keyboard_check(ord('S')),0);
key_right = max(keyboard_check(vk_right),keyboard_check(ord('D')),0);
key_left = -max(keyboard_check(vk_left),keyboard_check(ord('A')),0);

key_jump = max(keyboard_check(vk_up),keyboard_check(ord('W')),0);
