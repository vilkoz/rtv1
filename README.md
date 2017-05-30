# RTv1
Ray tracer project for UNIT Factory, made using minilibx

## Screenshot
![two spots scene](http://i.imgur.com/fCFMVJ4.png)
[more screenshots on imgur](http://imgur.com/a/efMht)

## Downloading and running

```bash
git clone https://github.com/vilkoz/rtv1.git && cd rtv1 && make
```

run, you can find example scenes in scenes dir
```bash
./RTv1 scene_file
```

## Scene file example 
```
l 100 300 300
c 300 600 0 -1 -2 0
# o center: x y z dir: x y z alpha height color
o 100 0 0 1 0 0 30 10000 0xffff00
# p center: x y z dir: x y z color
p 0 0 0 1 0 0 0xff00ff
# s center: x y z radius color
s 100 -100 100 50 0xff
```
