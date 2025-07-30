#!/bin/bash

# This script displays the IDs of the last 5 git commits.
git log -n 5 --pretty=format:%H
