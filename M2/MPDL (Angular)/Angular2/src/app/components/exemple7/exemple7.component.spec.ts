import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { Exemple7Component } from './exemple7.component';

describe('Exemple7Component', () => {
  let component: Exemple7Component;
  let fixture: ComponentFixture<Exemple7Component>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ Exemple7Component ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(Exemple7Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
