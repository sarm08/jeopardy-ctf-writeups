# DownUnder CTF 2020: Forensics: Spot the Difference
</br>**Category:** Forensics **Poits:** 327 points
</br></br>
**Description:**</br>
An employee's files have been captured by the first responders. The suspect has been accused of using images to leak confidential infomation, steghide has been authorised to decrypt any images for evidence!
</br>
**Attachment:** [Publish.zip](Publish.zip) (sha256: be6fd22e658b51124da5a608cc50e5fdc6698772a024cfe4dd9fb393f6ee5227)

## Solution
Unziping the given file, we get a set of directories with some text files and images:

```
Publish
├── badfiles
|   |-- 008532319cb53713de8ef1c979ab526d.jpg
|   |-- 010bd1036defc5c5df774b48ad86f346.jpg
|   |-- ...
|   |-- < a lot more images here>
├── .config
│   ├── Reminder.png
│   └── secret
        |-- 1
        |   |-- 1.txt
        |   |-- ....
        |   |-- 40.txt
        |-- ...
        |-- 40
        |   |-- 1.txt
        |   |-- ...
        |   |-- 40.txt
├── Desktop
│   ├── (2) UTS Cyber Security Society - Facebook.url
│   ├── DownUnderCTF.url
│   └── UTS Cyber Security Society.url
├── Downloads
│   └── DownUnderCTF _ FAQs.pdf
├── Images
│   ├── 1onp4t.jpg
│   ├── download.jfif
│   ├── NPC_wojak_meme.png
│   └── p072ms6r.jpg
├── Messages
│   └── Annotation 2020-09-10 184734.png
├── Music
│   └── EhD-T_UUwAAYjx1.jfif
└── Videos
    └── tenor.gif

9 directories, 12 files
```

From the challenge description, we'll have to use `steghide` on the images, but with what passphrase? Going to ./Publish/.config/secret , we get a lot of text files. Let's go through them to see if we can spot something suspicious.

```
$ find Publish/.config/secret/ -type f -exec cat {} \;
LaW4qx13G1SUERWkL0c0H3ElF1EFHUcaEaO3oJ9nq0kVp3SvoxSTnzkPMRA4n0qJ
GTcvnTqlpIuVJHcQqz95nxq6G015M2M5FSumIz5lEIELE2gnFzgGHHWbrHyUpISa
D0MIFTS1H0gOMIMwJRc1GRI0pIAYnHuVLISxqTIRLaSyJIcWF2g4o05Lpx10IKcW
oacJMxMlHzMhEHASqyuxn1EynJyWn29SL1MmGxMOoTgHrHcIGUqTESIWJzc5pz5u
DzyKHayfDH1BGxSfLauuM29LraIQo0I4JyWvG2AXMxWhFHMPpHWRpUWlFHy0LySV
...
CjEyMzRJc0FTZWN1cmVQYXNzd29yZA==
...
p3yII0S3oUWlGT9zFUEhHJ9Ko1yUHSuELz5kpxMcMII5ozS4nIyuq0SzESWaoxkD
JKuzIKEJESWDL1qELxMbnJICIaqIpz5xF0IBEIcCpKq5JJIEIJ9ELzy0D1uCo3AG
MJAKpJ9cF3yBqyOLpHWzEIMjI2q4q3W5pycLJx9uD0ISL1S1JHIjn1OKGSAUqx12
E0IZEKcQoJgQJaOwMJA3MH5iEHAfo1ywoyq1GKMmq0uFI3SVH2SXq0SIG0MzL3EC
```

There's a line that's smaller than the others, and it looks like it's base64 encoded.

```
echo -n CjEyMzRJc0FTZWN1cmVQYXNzd29yZA== | base64 -d
1234IsASecurePassword
```

And we found the passphrase. Now we just need to decrypt the images:

```
$ for i in $(ls Publish/badfiles/); do steghide extract -sf Publish/badfiles/$i -p 1234IsASecurePassword; done
steghide: could not extract any data with that passphrase!
...
steghide: could not extract any data with that passphrase!
wrote extracted data to "SecretMessage.txt".
steghide: could not extract any data with that passphrase!
...
steghide: could not extract any data with that passphrase!
```

```
$ cat SecretMessage.txt
DUCTF{m0r3_th4n_M33ts_th3_ey3}
```

## Flag
> DUCTF{m0r3_th4n_M33ts_th3_ey3}
