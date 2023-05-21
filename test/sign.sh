#!/bin/bash
openssl dgst -sha1 -binary <$1 | openssl dgst -sha1 -sign dsa_priv.pem | openssl enc -base64 >$2
