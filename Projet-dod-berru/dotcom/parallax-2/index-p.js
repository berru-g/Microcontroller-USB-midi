/*script by  Robert Gil Baptista */
let text = document.getElementById('text');
let sat = document.getElementById('sat');
let stars = document.getElementById('stars');
let btn = document.getElementById('btn');
let rocks = document.getElementById('rocks');
let cosmos = document.getElementById('cosmos');
let mountain = document.getElementById('mountain');
let header = document.getElementById('header');

window.addEventListener('scroll', function() {
    let value = window.scrollY;

    text.style.top = 15 + value * -.1 + '%';
    stars.style.top = value * -1.5 + 'px';
    stars.style.left = value * 2 + 'px';
    sat.style.top = value * -1.5 + 'px';
    sat.style.left = value * -5 + 'px';
    btn.style.marginTop = value * 1.5 + 'px';
    rocks.style.top = value * -.12 + 'px';
    cosmos.style.top = value * .25 + 'px';
    header.style.top = value * .5 + 'px';
})