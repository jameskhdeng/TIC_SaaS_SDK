#! /bin/sh

git add .
git commit -m "$1 版本"
git push
git tag -a "$1" -m "$1 版本"
git push --tags

exit 0