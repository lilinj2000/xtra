#!/usr/bin/env python

import json

xtra = { 
    "exchange_id": 1,
    "participant_id": "0148",
    "user_id": "88991042d",
    "password": "1",
    "client_id": "88991042d",
    "account_id": "88991042",
    "front_address": "tcp://127.0.0.1:122"
    }

sink1 = {
    "sink": {
        "type": "stdout_sink_mt",
        "level": "trace"
        }
    }

sink2 = {
    "sink": {
        "type": "rotating_file_sink_mt",
        "file_name": "xtra.log",
        "max_file_size": 5000000,
        "max_files": 10
        }
    }

log = {
    "level": "trace",
    "sinks": [sink1, sink2]
    }

test = {
    "instru": "cu1712",
    "price": 35670,
    "volume": 10
    }

config = {
    "xtra": xtra,
    "log": log,
    "test": test
    } 

with open('xtra.json', 'w') as f:
    json.dump(config, f, sort_keys=True, indent=4)
