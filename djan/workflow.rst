Project
---------------

.. code-block:: console

    django-admin startproject proj

    python manage.py startapp hello
    python manage.py startapp newyear
    python manage.py startapp tasks

    python manage.py runserver

Install apps e.g. "hello" on ``settings.py``.

Add urls.py to project ``urls.py``::

    from django.urls import include, path

    urlpatterns = [
        path("hello/", include("hello.urls")),]


Hello
------------
Dynamic url path into jinja template.

Urls::

    from . import views

    urlpatterns = [
        path("", views.index, name="index"),
        path("<str:name>", views.greet, name="greet"),

Views::

    def greet(request, name: str):
    return render(request, "hello/greet.html", {
        "name": name.capitalize()
    })

Templates:

.. code-block:: console

    <!DOCTYPE html>
    <html lang="en">
        <head>
            <title>Hello</title>
        </head>
        <body>
            <h1>hello {{ name }}</h1>
        </body>
    </html>

Newyear
-----------------
Basic logic on page into jinja, static css.

Views::

    def index(request):
    now = datetime.datetime.now()
    return render(request, "newyear/index.html",{
        "newyear": now.day == 1 and now.month == 1
    })

Template:

.. code-block:: console

    {% load static %}
    <!DOCTYPE html>
    <html lang="en">
        <head>
            <title>Is it new year</title>
            <link href="{% static 'newyear/styles.css' %}" rel="stylesheet">
        </head>
        <body>
            {% if newyear %}
                <h1>YES</h1>
            {% else %}
                <h1>NO</h1>
            {% endif %}
        </body>
    </html>

Static css:

.. code-block:: console

    h1 {
        font-family: sans-serif;
        font-size: 90px;
        text-align: center;
    }

Tasks
--------------
Form input.

views::

    from django.http import HttpResponseRedirect
    from django.shortcuts import render
    from django import forms
    from django.urls import reverse


    class NewTaskForm(forms.Form):
        task = forms.CharField(label="New Task")
        priority = forms.IntegerField(label="Priority", min_value=1, max_value=10)

    # Create your views here.
    def index(request):
        if "tasks" not in request.session:
            request.session["tasks"] = []
        return render(request, "tasks/index.html", {
            "tasks": request.session["tasks"]
        })

    def add(request):
        if request.method == "POST":
            form = NewTaskForm(request.POST)
            if form.is_valid():
                task = form.cleaned_data["task"]
                request.session["tasks"] += [task]
                return HttpResponseRedirect(reverse("tasks:index"))
            else:
                return render(request, "tasks/add.html",{
                    "form":form
                })

        return render(request, "tasks/add.html", {
            "form": NewTaskForm()
        })


Templates:

layout, jinja for, url link.

.. code-block:: console

    <!DOCTYPE html>
    <html lang="en">
        <head>
            <title> </title>
        </head>
        <body>
            {% block body %}
            {% endblock %}
        </body>
    </html>

.. code-block:: console

    {% extends "tasks/layout.html" %}

    {% block body %}
        <h1>Tasks</h1>
        <ul>
            {% for task in tasks %}
                <li>{{ task }}</li>
            {% empty %}
                <li>no task</li>
            {% endfor %}
        </ul>
        <a href="{% url 'tasks:add' %}">Add a New Task</a>
    {% endblock %}

.. code-block:: console

    {% extends "tasks/layout.html" %}

    {% block body %}
        <h1>add task</h1>
        <form action="{% url 'tasks:add' %}" method="post">
            {% csrf_token %}
            {{ form }}
            <input type="submit">
        </form>
        <a href="{% url 'tasks:index' %}">View Tasks</a>
    {% endblock %}


Csrf config:

.. code-block:: console

    python manage.py migrate
