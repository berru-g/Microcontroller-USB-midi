<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>make&amp;play PLAN</title>
  <link rel="stylesheet" href="https://stackedit.io/style.css" />
</head>

<body class="stackedit">
  <div class="stackedit__html"><h1 align="center">
  <a href="https://berru-g.github.io/Make-Play/"><img src="https://github.com/berru-g/Make-Play/blob/main/src/dod.gif?raw=true
    " width="500px" title="     Revenir au site"></a>
  <br>Make &amp; Play <br>
  <i align="center" >[Drafting in progress]</i>

</h1>
<h4 align="center">Controller USB - midi _ V 1.0.1</h4>
<p align="center">
  <a href="https://github.com/berru-g/Microcontroller-USB-midi/blob/main/Projet-dod-berru/C%2B%2B/encore_un_teste_midi_PAD/encore_un_teste_midi_PAD.ino">Code</a> •
  <a href="https://github.com/berru-g/Microcontroller-USB-midi/tree/main/Projet-dod-berru/bootloader">Electronique</a> •
  <a href="https://github.com/berru-g/Microcontroller-USB-midi/tree/main/Projet-dod-berru/3D">Plan 3D</a> •
  <a href="https://github.com/berru-g/Microcontroller-USB-midi/pulls">Contribution</a> •
  <a href="https://www.gnu.org/licenses/old-licenses/gpl-2.0.html">GNU General Public License v2.0</a> •
  <a href="https://berru-g.github.io/Make-Play/">🛒</a>
</p>
<h2 id="what-is-this-">What is this ?</h2>
<p>Microcontroller usb midi lowcost To play on <a href="https://ableton.com">Ableton</a>, Arena or any other music or video creation software.</p>
<p><em>This tool will allow you to map your effects to the desired potentiometer and key. 
  To do this, do <pre><code>ctrl+m</code></pre> in Ableton, select effet and push your btn or pot. </em></p>
  <p align="center">🎹 - &#128187; - &#128266;</p>

<h2 id="option">Option</h2>
<p>Refer directly to your plan according to the format of your M&amp;P or you can feed your curiosity</p>
<ul>
<li>The version plug &amp; play</li>
<li>The DIY Kit</li>
<li>The soldering kit</li>
<p align="right">choice <a href="https://berru-g.github.io/Make-Play/">your version 🛒</a></p>
</ul>
<h2>Plan step by step</h2> 
<h3 id="step-1---code--">Step 1 - code for adapt your project if necessary-</h3>
<pre><code>#include &lt;MIDI.h&gt;
MIDI_CREATE_DEFAULT_INSTANCE();
</code></pre>
<p id="if-you-decide-to-start-this-project-really-from-the-beginning-then-a-simple-atmega-328p-as-well-as-three-components-will-be-necessary-i-invite-you-in-this-case-to-flash-bootloader-the-microcontroller.--and-follow-that-plan.">If you decide to start this project really from the beginning, then a simple AtMega 328p as well as three components will be necessary, I invite you in this case to “flash”, <a href="https://github.com/berru-g/Microcontroller-USB-midi/tree/main/Projet-dod-berru/bootloader">bootloader</a> the microcontroller.  And follow that plan.</p>
<p id="find-the-full-code-here-.-the-digital-and-analog-inputs-and-outputs-are-declared-at-the-maximum-number-for-an-atméga-328p-type-microcontroller-these-can-be-multiplied-if-a-multiplexer-is-added.-the-code-must-then-provide-a-matrix-of-inputs-andor-outputs.">Find the full <a href="https://github.com/berru-g/Microcontroller-USB-midi/blob/main/Projet-dod-berru/C++/encore_un_teste_midi_PAD/encore_un_teste_midi_PAD.ino">code here</a> . The digital and analog inputs and outputs are declared at the maximum number for an AtMéga 328p type microcontroller, these can be multiplied if a multiplexer is added. The code must then provide a matrix of inputs and/or outputs.</p>
<p><img src="https://github.com/berru-g/Microcontroller-USB-midi/blob/main/Projet-dod-berru/bootloader/ATMega329P.jpg?raw=true" align="center" alt="github.com/berru-g"></p>
<h6>Plan &amp; code of my <a href="https://www.hackster.io/gleberruyer/midi-pad-80c178">first prototyp</a>, based on Arduino.</h6>
<h3 id="step-2">Step 2 - make -</h3>
<p>Despite the simplicity, it necessary to specify to take precautions concerning the assembly, because the facade is fragile. I advise you to follow the plan to have a solid tool once fixed to its support.</p
  ><p>Despite our choice to use quality components, the potentiometers can be weakened when shipped, we advise you to check their stability before assembly and we will send a PCB if necessary*. [the return of this product currently = 0.001%]
  *do not thank the postman.</p>
<p><img src="https://github.com/berru-g/Make-Play/blob/main/src/plan.png?raw=true" align="center" width="400px" alt="github.com/berru-g"></p>
<h3 id="step-3">Step 3 - config in Ableton® -</h3>
<p>When you are ready to play, configure your M&P as below. Select option, preference,Audio & link-midi. Important, choose the 9600 sampling frequency carefully for better optimization.</p>
<p><img src="https://github.com/berru-g/Make-play-PLAN/blob/main/src/bault.png?raw=true" align="center" alt="github.com/berru-g"></p>
<p><img src="https://github.com/berru-g/Make-play-PLAN/blob/main/src/input.png?raw=true" align="center" alt="github.com/berru-g"></p>
<h3 id="step 4">Step 4 play</h3>
<p>Share your creation in Make & Play Community 😁</p>
<p>Choice <a href="https://berru-g.github.io/Make-Play/">your colori</a></p>
<h2 align="center"> 2020 v-1.0.1</h2>
<p><a href="https://berru-g.github.io/Make-Play/">Make and play</a>  is Free, for used and/or modify it under the terms of the <a href="https://www.gnu.org/licenses/gpl.html">GNU General Public License</a> .</p>
</div>
</body>

</html>
