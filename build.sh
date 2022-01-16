# command for converting equations; manual crop after
qlmanage -t -s 1000 -o ./svg ./svg/*.svg
qlmanage -t -s 1000 -o ./svg2 ./svg2/*.svg

mv -f README_files/figure-html/* figures/ && rm -rf README_files && rm -rf README.html