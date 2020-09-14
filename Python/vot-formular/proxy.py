import requests
from stem import Signal
from stem.control import Controller
from fake_useragent import UserAgent


def new_identity():
    with Controller.from_port(port=9051) as contr:
        contr.authenticate(password='parola123')
        contr.signal(Signal.NEWNYM) # Works despite the error
        print("New Tor connection")

def get_ip():
    headers = { 'User-Agent' : UserAgent().random }
    proxies = {
        'http' : 'socks5://127.0.0.1:9050',
        'https' : 'socks5://127.0.0.1:9050'
    }
    return requests.get('https://api.ipify.org', proxies=proxies, headers=headers).text

def fresh_identity():
    last_identity = get_ip()
    while True:
        new_identity()
        current_identity = get_ip()
        if current_identity != last_identity:
            break