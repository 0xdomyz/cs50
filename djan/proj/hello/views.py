from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
def index(request):
    return render(request, "hello/index.html")

def aaa(request):
    return HttpResponse("hello aaa")

def bbb(request):
    return HttpResponse("hello bbb")

def greet(request, name: str):
    return render(request, "hello/greet.html", {
        "name": name.capitalize()
    })