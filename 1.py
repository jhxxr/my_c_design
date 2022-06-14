import requests
a = "https://jhx.asia"
re = requests.get(url=a)
res = re.text
print(res)
