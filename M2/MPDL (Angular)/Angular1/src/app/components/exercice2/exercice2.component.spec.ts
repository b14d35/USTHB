import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { Exercice2Component } from './exercice2.component';

describe('Exercice2Component', () => {
  let component: Exercice2Component;
  let fixture: ComponentFixture<Exercice2Component>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ Exercice2Component ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(Exercice2Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
