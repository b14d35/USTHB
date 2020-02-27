import { BrowserModule } from "@angular/platform-browser";
import { NgModule } from "@angular/core";
import { FormsModule } from "@angular/forms";

import { AppComponent } from "./app.component";
import { Example1Component } from "./components/example1/example1.component";
import { HeaderComponent } from "./components/header/header.component";
import { Example2Component } from "./components/example2/example2.component";
import { Example3Component } from "./components/example3/example3.component";
import { Example4Component } from "./components/example4/example4.component";
import { Example5Component } from "./components/example5/example5.component";
import { Example6Component } from "./components/example6/example6.component";
import { Exercice1Component } from "./components/exercice1/exercice1.component";
import { Exercice2Component } from "./components/exercice2/exercice2.component";

@NgModule({
  declarations: [
    AppComponent,
    Example1Component,
    HeaderComponent,
    Example2Component,
    Example3Component,
    Example4Component,
    Example5Component,
    Example6Component,
    Exercice1Component,
    Exercice2Component
  ],
  imports: [BrowserModule, FormsModule],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule {}
