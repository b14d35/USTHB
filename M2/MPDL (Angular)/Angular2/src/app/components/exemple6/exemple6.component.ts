import { Component, OnInit } from '@angular/core';
import { Training } from '/app/model/training';
import { HttpClient } from '@angular/common/http';
import { CountryService } from '/app/services/country/country.service';
import { Country } from '/app/model/country';


@Component({
  selector: 'app-exemple6',
  templateUrl: './exemple6.component.html',
  styleUrls: ['./exemple6.component.scss']
})
export class Exemple6Component implements OnInit {

  data: Country[];

  constructor(private $ser: CountryService) { }

  ngOnInit() {

  }

  getData() {
    this.$ser.getData().subscribe(
      s => this.data = s,
      error => {
        alert('error !!' + error.status);
        console.log(error);
      }

    );
  }

}
