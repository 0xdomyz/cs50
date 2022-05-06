start proj, app
--------------------

.. code-block:: console

    django-admin startproject airline
    cd airline
    python manage.py startapp flights

Install app.

Set up proj, app ``urls.py``.

Create models
-----------------

In ``models.py``::

    class Airport(models.Model):
        code = models.CharField(max_length=3)
        city = models.CharField(max_length=64)

        def __str__(self):
            return f"{self.id}: {self.code} is {self.city}"

    class Flight(models.Model):
        origin = models.ForeignKey(Airport, on_delete=models.CASCADE, related_name="departures")
        destination = models.ForeignKey(Airport, max_length=64, on_delete=models.CASCADE, related_name="arrivals")
        duration = models.IntegerField()

        def __str__(self):
            return f"{self.id}: {self.origin} to {self.destination}"

Apply changes to database via migration:

.. code-block:: console

    python manage.py makemigrations
    python manage.py migrate

Use shell to write python codes to operate on the app:

.. code-block:: console

    python manage.py shell

Shell create object::

    >>> from flights.models import Flight
    >>> f = Flight(origin="New York", destination="London", duration=415)
    >>> f.save()
    >>> Flight.objects.all()
    <QuerySet [<Flight: Flight object (1)>]>

Shell printing object, delete obj::

    >>> from flights.models import Flight
    >>> flights = Flight.objects.all()
    >>> flights
    <QuerySet [<Flight: 1: New York to London>]>
    >>> flights.first()
    <Flight: 1: New York to London>
    >>> flights.first().destination
    >>> 'London'
    >>> flights.first().delete()
    (1, {'flights.Flight': 1})
    >>> flights
    <QuerySet []>

Shell create objs::

    >>> from flights.models import Airport
    >>> jfk = Airport(code="JFK", city="New York")
    >>> jfk.save()
    >>> lhr = Airport(code="LHR", city="London")
    >>> lhr.save()
    >>> cdg = Airport(code="CDG", city="Paris")
    >>> cdg.save()
    >>> nrt = Airport(code="NRT", city="Tokyo")
    >>> nrt.save()

Shell query obj::

    >>> from flights.models import Flight
    >>> Flight(origin=jfk, destination=lhr, duration=415)
    <Flight: None: 1: JFK is New York to 2: LHR is London>
    >>> Flight(origin=jfk, destination=lhr, duration=415).save()
    >>> f = Flight(origin=jfk, destination=lhr, duration=415)
    >>> f.origin
    <Airport: 1: JFK is New York>
    >>> f.origin.city
    'New York'
    >>> f.origin.code
    'JFK'
    >>> lhr.arrivals.all()
    <QuerySet [<Flight: 1: 1: JFK is New York to 2: LHR is London>]>

Index page
--------------

Add code to urls, views, templates::

    path("", views.index, name="index"),

::

    def index(request):
        return render(request, "flights/index.html", {
            "flights": Flight.objects.all()
        })

.. code-block:: console

    <!DOCTYPE html>
    <html>
        <head>
            <title>Flights</title>
        </head>
        <body>
            {% block body %}
            {% endblock %}
        </body>
    </html>

    {% extends "flights/layout.html" %}

    {% block body %}
        <h1>Flights</h1>
        <ul>
            {% for flight in flights %}
                <li>Flight {{ flight.id }}: {{ flight.origin }} to {{ flight.destination }}</li>
            {% endfor %}
        </ul>

    {% endblock %}

Use the administration account
---------------------------------

.. code-block:: console

    python manage.py createsuperuser
    python manage.py runserver

Goto /admin, log in, add objects.

Flight page
-----------------

Add code to urls, views, templates::

    path("<int:flight_id>", views.flight, name="flight")

::

    def flight(request, flight_id):
        flight = Flight.objects.get(pk=flight_id)
        return render(request, "flights/flight.html", {
            "flight": flight
        })

.. code-block:: console

    {% extends "flights/layout.html" %}

    {% block body %}
        <h1>Flights {{ flight.id }}</h1>

        <ul>
            <li>origin: {{ flight.origin }}</li>
            <li>destination: {{ flight.destination }}</li>
            <li>duration: {{ flight.duration }}</li>
        </ul>
    {% endblock %}

Passengers
--------------

Add to models::

    class Passenger(models.Model):
        first = models.CharField(max_length=64)
        last = models.CharField(max_length=64)
        flights = models.ManyToManyField(Flight, blank=True, related_name="passengers")
        
        def __str__(self) -> str:
            return f"{self.first} {self.last}"

Register on admin::

    admin.site.register(Passenger)

Migrate:

.. code-block:: console

    python manage.py makemigrations
    python manage.py migrate

Run.

Display passengers on flight
--------------------------------

Views::

    def flight(request, flight_id):
        flight = Flight.objects.get(pk=flight_id)
        return render(request, "flights/flight.html", {
            "flight": flight,
            "passengers": flight.passengers.all()
        })

Templates:

.. code-block:: console

    <li>
        <a href="{% url 'flight' flight.id %}">
        Flight {{ flight.id }}: {{ flight.origin }} to {{ flight.destination }}
        </a>
    </li>

.. code-block:: console

    <ul>
        {% for passenger in passengers %}
            <li>{{ passenger }}</li>
        {% empty %}
            <li>Empty</li>
        {% endfor %}
    </ul>

    <a href="{% url 'index' %}">Back to list</a>

Book flight
-------------

Urls::

    path("<int:flight_id>/book", views.book, name="book")

Views::

    from django.http import HttpResponseRedirect
    from django.urls import reverse
    from .models import Flight, Passenger

    def flight(request, flight_id):
        flight = Flight.objects.get(pk=flight_id)
        return render(request, "flights/flight.html", {
            "flight": flight,
            "passengers": flight.passengers.all(),
            "non_passengers": Passenger.objects.exclude(flights=flight).all()
        })

    def book(request, flight_id):
        if request.method == "POST":
            print(request.POST["passenger"])
            flight = Flight.objects.get(pk=flight_id)
            passenger = Passenger.objects.get(pk=int(request.POST["passenger"]))
            passenger.flights.add(flight)
            return HttpResponseRedirect(reverse("flight", args=(flight.id,)))


Teamplates:

.. code-block:: console

    <h2>Add passenger</h2>

    <form action="{% url 'book' flight.id %}" method="post">
        {% csrf_token %}
        <select name="passenger">
            {% for passenger in non_passengers %}
                <option value="{{ passenger.id }}"> {{ passenger }}</option>
            {% endfor %}
        </select>
        <input type="submit">
    </form>

Customise admin UI
-----------------------

Admin::

    class FlightAdmin(admin.ModelAdmin):
        list_display = ("id", "origin", "destination", "duration")

    class PassengerAdmin(admin.ModelAdmin):
        filter_horizontal = ("flights",)

    admin.site.register(Flight, FlightAdmin)
    admin.site.register(Airport)
    admin.site.register(Passenger, PassengerAdmin)


Authentication
-------------------







