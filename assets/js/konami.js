// a key map of allowed keys
var allowedKeys = {
    37: 'left',
    38: 'up',
    39: 'right',
    40: 'down',
    65: 'a',
    66: 'b'
  };
  
  // the 'official' Konami Code sequence
  var konamiCode = ['up', 'up', 'down', 'down', 'left', 'right', 'left', 'right', 'b', 'a'];
  
  // a variable to remember the 'position' the user has reached so far.
  var konamiCodePosition = 0;
  
  // add keydown event listener
  document.addEventListener('keydown', function(e) {
    // get the value of the key code from the key map
    var key = allowedKeys[e.keyCode];
    // get the value of the required key from the konami code
    var requiredKey = konamiCode[konamiCodePosition];
  
    // compare the key with the required key
    if (key == requiredKey) {
  
      // move to the next key in the konami code sequence
      konamiCodePosition++;
  
      // if the last key is reached, activate cheats
      if (konamiCodePosition == konamiCode.length) {
        activateCheats();
        konamiCodePosition = 0;
      }
    } else {
      konamiCodePosition = 0;
    }
  });
  
  function activateCheats() {
    var audio = new Audio('./assets/sound/egg.ogg');
    audio.play();

    var greenIcon = L.icon({
        iconUrl: './assets/img/placeholder/dev/pone.png',
    
        iconSize:     [38, 38], // size of the icon 
        popupAnchor:  [0, -10] // point from which the popup should open relative to the iconAnchor
    });
    var DevMarker = L.marker([43.6547,6.1326], {icon: greenIcon}).addTo(mymap);
    DevMarker.bindPopup("<b>Bonjour!</b><br>je suis <b>Giaccone Rémi</b> le dévelopeur de se logiciel, et j'habbite a Régusse.<br><br>Si tu vois se message c'est que tu as réusi a metre un clavier sur cette bornne et tu as fait le konami code!").openPopup();
  }