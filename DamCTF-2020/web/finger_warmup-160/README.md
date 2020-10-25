# Dam CTF 2020: Web: finger-warmup
</br>**Category:** Web **Points:** 160 points
</br></br>
**Description:**</br>
A finger warmup to prepare for the rest of the CTF, good luck!</br>
You may find [this](https://realpython.com/python-requests/) or [this](https://programminghistorian.org/en/lessons/intro-to-beautiful-soup) to be helpful.
> finger-warmup.chals.damctf.xyz

## Solution
Going to the website, we are presented with a link that sends us to a new page, but this new page is the same as the previous one, except that sends us to a different page.

So, it's clear that we need to automate this, until we reach the page that has the flag.

### Script
```python
import requests
import re

url = 'https://finger-warmup.chals.damctf.xyz/'
r = requests.get(url)
print(r.text)

while('dam{' not in r.text):
    print('----------------------------------------------------------')
    text = r.text
    b = text.find('"') + 1
    e = text.find('"', b)
    directory = text[b:e]
    url = 'https://finger-warmup.chals.damctf.xyz/' + directory
    r = requests.get(url)
    print(r.text)
```

After a few minutes, we get the flag.

## Flag
> dam{I_hope_you_did_this_manually}
