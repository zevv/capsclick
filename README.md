

use this:

```
xmodmap -e 'remove Lock = Caps_Lock'
xmodmap -e "clear lock"
xmodmap -e "keycode 66 ="
xset -r 66
xmodmap -e "keycode 133 ="
xset -r 133
```
