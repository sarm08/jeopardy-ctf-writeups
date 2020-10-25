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
    #print(directory)
    url = 'https://finger-warmup.chals.damctf.xyz/' + directory
    r = requests.get(url)
    print(r.text)


