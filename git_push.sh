#!/bin/bash

read -r -p "remote: " REMOTE
read -r -p "branch: " BRANCH
git checkout "$BRANCH"
git add .
read -r -p "commit message: " MSG
git commit -m "$MSG"
read -r -p "push?[y/n]" PUSH
if [ "$PUSH" == "y" ]; then
    git push "$REMOTE $BRANCH"
else
    exit 1
fi
