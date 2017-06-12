<h1> Quadriplegic-Remote</h1>
<p>Designed and built a TV remote with photoresistors for patients with quadriplegia, muscular dystrophy, and spina bifida using C++ and Arduino.
</p>

<h1> Specifications </h1>
<p>
Our design looks like an inverse V-shaped handrest with the circuit-board, battery pack, and Arduino microcontroller underneath the handrest and a photoresistor embedded into the board; the Arduino board underneath is connected to another separate infrared trasmitter board that has an infrared LED lightbulb. The two wood pieces of our design are connected by hot glue at a 90 degree angle, each wood piece is 5.5 by 4.25 inches. 
</p>

<h1> Functionality</h1>
<p> When the Arduino is first turned on (or reset through the reset button), it measures ambient light for 10 seconds with the photoresistor and records the average value attained within those 10 seconds. The patient then puts his/her hand over the armrest to cover the photoresistor; the Arduino microcontroller will check every second to see if the hand is lifted (and if the photoresistor is once again exposed to light). If it is still dark, which means the patient's hand is over the photoresistor, nothing happens. Else, if light has been exposed, meaning the patient has lifted his/her hand, then the Arduino triggers a channel change.</p>
