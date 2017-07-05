# Plantilla para un Plugin de Cordova
======

Plantilla base para construir un plugin de iOS y Android.

======
# ¿Qué es un plugin de Cordova?

Cordova es un conjunto de herramientas que funcionan como puente para crear aplicaciones nativas e hibridas que se comunican a tráves de código Javascript.

Ese puente nos permite hacer cosas sencillas o tan complejas nativas que no se incorporan a los estandares de la Web.

Construir plugins de Cordova significa qu estamos escribiendo algo de JavaScript para invocar a algún código nativo (Objetive-c, Java, entre otros) que tambien deberemos de escribir y devolver el resultado a nuestro JavaScript.

En resumen, construimos un plugin de Cordova cuando queremos hacer algo nativo que aún no puede realizar el WebKit, como acceder a los datos de HealthKit, al scanner de huella, a la conexión bluetooth o a un SDK de terceros que permiten la conexión con dispositivos como impresoras y lectores.

# Construcción de nuestro propio Plugin:

Frameworks como Ionic cuentan con una libreria extensa de herramientas nativas en las cuales posiblemente encontrarás lo que buscas [IonicFramework](https://ionicframework.com/docs/native/), pero ¿cómo hacer uno propio? Bueno Cordova habilita una documentación para este fin: [Plugin Development Guide](https://cordova.apache.org/docs/en/7.x/guide/hybrid/plugins/index.html), sin embargo despues de mucho buscar y probar diferentes alternativas me guié finalmente por esta página: [How to write Cordova Plugins](https://medium.com/ionic-and-the-mobile-web/how-to-write-cordova-plugins-864e40025f2) la cúal se basa en una plantilla ya creada para clonar e instalar en nuestro proyecto, con el fin de entender y documentar un poco más me decidi a en base a dicha plantilla crear una propia.

# Implementación en Ionic:

```
import { Component } from '@angular/core';
//Agregar Platform para poder evaluar si ya se cargo y esta lista la plataforma
import { NavController, Platform } from 'ionic-angular';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {

  constructor(public navCtrl: NavController,public platform: Platform) {
  }

  ionViewDidLoad() {  
    //Verifica si ya se encuentra lista la plataforma  
    this.platform.ready().then(() => {
          //Realiza el llamado al plugin e invoca segun el resultado la funcion correspondiente
          (<any>window).MiPlugin.saludo('Mundo!!!', this.successCallback, this.errorCallback);
    });
  }

  //Funcion para desplegar la respuesta cuando es satisfactorio
  successCallback(message){
      alert(message);
  }

  //Funcion si hubo un error
  errorCallback(){
      alert("Hubo un error");
  }

}

```

Fuente de referencia:

https://medium.com/ionic-and-the-mobile-web/how-to-write-cordova-plugins-864e40025f2
