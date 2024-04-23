#!/bin/bash

function dm {
  # swap stderr with stdout, so we capture stderr
  dest=$(dmenu "$@" 3>&2 2>&1 1>&3)
  res=$?

  if (( res == 0 )) && [ -n "$dest" ]; then
    cd "$dest" || return
  else
    # show the error
    echo "$dest"
  fi
}
