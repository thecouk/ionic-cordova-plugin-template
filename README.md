Plantilla para un Plugin de Cordova
======

Plantilla base para construir un plugin de iOS y Android.

======

Implementación en Ionic:

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
