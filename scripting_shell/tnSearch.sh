#!/bin/sh
#Explanation:
# \(([0-9]\{3\})\|[0-9]\{3\}\) matches exactly three digits (e.g. 234) 
# with or without surrounded by parentheses. 
# \| performs the 'OR' operation.

# The first \( ... \) groups together the above format followed by a space or
# - or no space at all - ([ -]\?) does that.

# The \{2\} matches exactly two occurrences of the above
# The [0-9]\{4\} ' matches exactly one occurrence for a 4 digit number followed by a space


# tn 123-333-5555
# tn (333)333-4444
# tn 444 555 5555
# tn  1234567890
# 999999999999999
# 33334
# 453453453453453
# 3333 3333 3333
# 5555-555-555
# d
# sdfsa
# 333sdf
# 33333-43-222

grep '\(\(([0-9]\{3\})\|[0-9]\{3\}\)[ -]\?\)\{2\}[0-9]\{4\}' *

