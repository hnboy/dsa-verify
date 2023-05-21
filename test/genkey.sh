#!/bin/bash
openssl dsaparam 4096 > dsaparam.pem
openssl gendsa -out dsa_priv.pem dsaparam.pem
openssl dsa -in dsa_priv.pem -pubout -out dsa_pub.pem
rm dsaparam.pem
