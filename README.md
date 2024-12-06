This simply returns the Window Title of the currently active (focused) window, if it has one. Most, but not ALL windows do... It's kinda fun to play around with various elements of the Windows interface and see what it is calling stuff.

Note that Rainmeter skins have the full path and filename of the skin .ini file set as their window title. So in theory, you could have a skin that could return the path to some other skin when you click on the other skin.

```
[Rainmeter]
Update=1000
DynamicWindowSize=1
AccurateText=1
MouseOverAction=[!DisableMeasure MeasureActiveTitle]
MouseLeaveAction=[!EnableMeasure MeasureActiveTitle]

[Metadata]
Name=GetActiveTitle
Author=JSMorley
Information=Uses the GetActiveTitle plugin to retreive the Window Title of the currently active window.
License=Creative Commons Attribution-Non-Commercial-Share Alike 3.0
Version=Aug 19, 2019

[Variables]

[MeasureActiveTitle]
Measure=Plugin
Plugin=GetActiveTitle

[MeterActiveTitle]
Meter=String
MeasureName=MeasureActiveTitle
FontSize=11
FontWeight=400
FontColor=255,255,255,255
SolidColor=47,47,47,255
Padding=5,5,5,5
AntiAlias=1
DynamicVariables=1
LeftMouseUpAction=[!SetClip "[MeasureActiveTitle]"]
```
