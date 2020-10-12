# DownUnder CTF 2020: Misc: In a pickle
</br>**Category:** Miscellaneous **Points:** 200 points
</br></br>
**Description:**</br>
We managed to intercept communication between und3rm4t3r and his hacker friends.However it is obfuscated using something. We just can't figure out what it is. Maybe you can help us find the flag?
</br>
**Attachment:** [data](data)

## Solution
With the challenge name and the text inside the data file in mind, we can say that the data is a **pickle**, a serialized python object structure.

In order to retrieve the message, we will have to de-serialize the pickle: **unplickling**.

```python
import pickle

f = open('data', 'rb')

p = pickle.load(f)

for i in range(1,25):
    # The characters inside the flag are in decimal number, instead of ascii
    if type(p[i]) == int:
        print(chr(p[i]), end='')
    else:
        print(p[i], end='')

f.close()
```

## Flag
> DUCTF{p1ckl3_y0uR_m3554g3}
