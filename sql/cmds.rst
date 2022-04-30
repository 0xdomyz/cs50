admin

.. code-block:: console

    django-admin startproject airline
    cd airline
    python manage.py startapp flights
    python manage.py makemigrations
    python manage.py migrate
    python manage.py shell

Create object

.. code-block:: console

    In [1]: from flights.models import Flight
    In [2]: f = Flight(origin="New York", destination="London", duration=415)
    In [3]: f.save()
    In [4]: Flight.objects.all()
    Out[4]: <QuerySet [<Flight: Flight object (1)>]>

Printing object, delete obj

.. code-block:: console

    In [1]: from flights.models import Flight
    In [3]: flights = Flight.objects.all()
    In [4]: flights
    Out[4]: <QuerySet [<Flight: 1: New York to London>]>
    In [5]: flights.first()
    Out[5]: <Flight: 1: New York to London>
    In [6]: flights.first().destination
    Out[6]: 'London'
    In [8]: flights.first().delete()
    Out[8]: (1, {'flights.Flight': 1})
    In [9]: flights
Out[9]: <QuerySet []>

Create objs

.. code-block:: console

    In [2]: from flights.models import Airport
    In [3]: jfk = Airport(code="JFK", city="New York")
    In [4]: jfk.save()
    In [5]: lhr = Airport(code="LHR", city="London")
    In [6]: lhr.save()
    In [7]: cdg = Airport(code="CDG", city="Paris")
    In [8]: cdg.save()
    In [9]: nrt = Airport(code="NRT", city="Tokyo")
    In [10]: nrt.save()

Inspect obj

.. code-block:: console

    In [12]: from flights.models import Flight
    In [13]: Flight(origin=jfk, destination=lhr, duration=415)
    Out[13]: <Flight: None: 1: JFK is New York to 2: LHR is London>
    In [14]: Flight(origin=jfk, destination=lhr, duration=415).save()
    In [15]: f = Flight(origin=jfk, destination=lhr, duration=415)
    In [16]: f.origin
    Out[16]: <Airport: 1: JFK is New York>
    In [17]: f.origin.city
    Out[17]: 'New York'
    In [18]: f.origin.code
    Out[18]: 'JFK'
    In [19]: lhr.arrivals.all()
    Out[19]: <QuerySet [<Flight: 1: 1: JFK is New York to 2: LHR is London>]>

admin

.. code-block:: console

    python manage.py createsuperuser