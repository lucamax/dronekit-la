=================
About DroneKit-LA
=================

DroneKit Log Analyzer (DroneKit-LA) is a powerful open source *static analyzer* for ArduPilot logs.

The tool can read and analyze several log formats, including telemetry logs (tlogs), dataflash binary logs (.BIN)
and dataflash text dumps (.log), and output detailed error and warning information in several formats (json, text, summary). 
The output includes detailed information about the tests, including what tests were run, the results (pass, fail, warn), severity, 
and supporting evidence.

DroneKit-LA is also fast, memory efficient and extensible. It supports numerous analyzers
and has already proved itself capable of quickly analyzing very large logs. 


Key features
============

The main features of DroneKit-LA are:

- Lots of tests! If you need more, DroneKit-LA is readily extensible.
- Supports all the main input log types: 
  telemetry logs (tlogs), dataflash binary logs (.BIN) and dataflash text dumps (.log).  
- Detailed and informative output log format (.json). Output lists results (pass, fail, warn), 
  severity, and supporting evidence for all tests run.
- Additional output log formats to get summary information.
- Choice of which analyzers to run (all by default).
- Ability to customise tests for vehicle and frame type. 
  
  - Common tests are run on all platforms. 
  - Currently there are Copter and Plane specific tests (there are no Rover-specific tests).
- Fast and memory efficient. DroneKit-LA is capable of quickly analyzing very large files.
- Ready for integration into GCSs. 

  - The ``severity-score`` allows filtering and ordering of fail-cases by their relative seriousness.
  - The ``evidence`` field contains detail about the relevant values that were used
    to determine the pass, fail or warning status.  
  - The ``series`` field contains timing and series information for easy graphical 
    representation of problem areas.

How does it work?
=================

DroneKit-LA has been designed from the ground-up to provide an extensible framework for supporting different 
log input and output formats, and for creating tests (analyzers) which are independent of those formats and 
of each other.

The heart of this architecture is a *common model* of a vehicle log. 
Each log importer writes its data to this same model. 
Analyzers implement a framework which can query the model for log information, analyze it based on the
current vehicle and frame, and call standard methods to save the results.
The tool can then process the results and export them in the desired format(s). 

.. todo:: This would be much better with a UML class diagram.

The whole tool is written in C++ and can (currently) compile on a Linux computer.

  

Comparison to LogAnalyzer.py
============================

DroneKit-LA is a compelling alternative to **LogAnalyzer.py**.

The key advantages of DroneKit-LA are that it is much faster and more memory efficient, 
works on additional log formats (tlog), supports more and better tests, and provides
very detailed analysis information.

Both tools are open source and designed for easy extension. Both tools can run
on the main host PC development platforms used for ArduPilot development.

.. note::

    **LogAnalyzer.py** is a Python script, and can run anywhere Python is available.
    DroneKit-LA can be used on any platform that supports Vagrant (but can currently 
    only build and run *natively* on Linux).

**LogAnalyzer.py** has already been integrated into other Ground Control Station (GCS) 
analysis tools. Its XML-based output is basic, and readily presented to the user. 

Integrating DroneKit-LA's *json* output into a GCS is less straightforward as the output 
is more detailed, and consequently less human-readable.
DroneKit-LA can enable GCS developers to create better graphical analysis tools, 
as it provides detailed information about where issues occur in the logs/data series.



Open source community
=====================

DroneKit-Python is an open source project. 

You can find all the source code on `Github here <https://github.com/dronekit/dronekit-la>`_ and check out our permissive :doc:`Apache v2 Licence <license>`. 
If you want to join the community, then see our :doc:`contributing section <../contributing/index>` for ideas about how you can help.



Technical support
=================

If you run into questions that are not answered by this documentation, 
the best place to ask for help is the `DroneKit Forums <https://discuss.dronekit.io/>`_. 

If your problem turns out to be a bug, then it should be `posted on Github <https://github.com/dronekit/dronekit-la/issues>`_.
