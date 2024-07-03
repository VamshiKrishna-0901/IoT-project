# IoT-project
Traffic light management and controlling system

<b>Test Case 1:</b> No Vehicles Present <br>
<b>Description:</b> Test the system when no vehicles are detected. <br>
<b>Input:</b> No IR sensor detects a vehicle. <br>
<b>Expected Output:</b> The traffic signal remains green for the current lane and switches to red after the predefined time interval.
<br><br>

<b>Test Case 2:</b> One Lane with Vehicles<br>
<b>Description:</b> Test the system when vehicles are detected in only one lane.<br>
<b>Input:</b> One IR sensor detects vehicles, others do not.<br>
<b>Expected Output:</b> The traffic signal should remain green for the lane with vehicles until the vehicles pass or after a maximum green light duration, then switch to the next lane.<br>
<br>

<b>Test Case 3:</b> All Lanes with Vehicles<br>
<b>Description:</b> Test the system when vehicles are detected in all lanes.<br>
<b>Input:</b> All IR sensors detect vehicles.<br>
<b>Expected Output:</b> The traffic signal should prioritize lanes based on vehicle density, giving each lane a green light in a round-robin manner, ensuring no lane is starved.<br>
<br>

<b>Test Case 4:</b> High Vehicle Density in One Lane<br>
<b>Description:</b> Test the system when one lane has a significantly higher vehicle density.<br>
<b>Input:</b> One IR sensor detects high density, others detect low or medium density.<br>
<b>Expected Output:</b> The traffic signal should allocate more green light time to the lane with higher density, while still allowing other lanes to proceed in turn.<br>
<br>

<b>Test Case 5:</b> Equal Vehicle Density in All Lanes<br>
<b>Description:</b> Test the system when all lanes have equal vehicle density.<br>
<b>Input:</b> All IR sensors detect equal vehicle density.<br>
<b>Expected Output:</b> The traffic signal should switch lanes in a round-robin manner, ensuring equal green light time for all lanes.
