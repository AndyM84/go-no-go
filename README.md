# Go, No-Go

## Overview
"Go, No-Go" (GNG) will be an interactive simulation that focuses on engaging users with gradually increasing difficulty as they learn some of the systems that are verified in the hours and moments before a launch.  The controls and systems used will be powered by a custom rules engine built on top of Unreal Engine 4 to provide faster adjustment of the rules and a visually enticing interface for users.  Each level of difficulty will change the number of systems that require a "go, no-go," the range of control types for those GNG's, and will change the timescale.

## Gameplay
All scenarios are unique thanks to the rules engine, but the process will remain the same.

1. User starts scenario. (Improvement: Select spacecraft, manned/unmanned, weather seed, time of day/year)
  * Difficulty selected here (Show time scale and approx # of systems/controls)
2. Launchpad loads with (selected) spacecraft, countdown begins
3. As countdown progresses, chosen systems/controls run through their visualization and request "Go, No-Go" as necessary down the line
4. If launch is cleared, the system simulates launch and uses the rules engine as verification for whether or not the launch was successful

## Future Features
There are numerous ways in which the simulation could be expanded to add utility.  Here are just a few:

* Competition; Add ability to compete with friends by adding scoring based on metrics such as false-negative scrubs and success rates.
* 'Real' simulation; Perform 6 hours of multiplayer cooperative launch in real time.
* Data mining; User base can contribute to things such as improving automation or simulation logic for real launch systems.

## Rules Engine
The rules engine will be built in C++ to facilitate integration with existing simulations as well as any relevant data from external sources that can help with randomization or accuracy of the simulation.  The rules engine will have only two purposes:

1. Generate dynamic launch requirements for scenarios
2. Provide information for launch simulation to know when problems should occur
3. Interface with model rocket systems for real-life repurcussions

## Team Members
The following people are on the team currently, but more help is always welcome!

* Andrew Male
* Jordan Cain
* Matthew Hykes
* Moises Silva
* Steven Gugel
* Janice Dy

Also, feel free to come chat with us on [IRC](http://widget01.mibbit.com/?settings=522f69525a0c38ae917e5c5a66d6bab3&server=irc.zibings.net&channel=%23GoNoGo)
