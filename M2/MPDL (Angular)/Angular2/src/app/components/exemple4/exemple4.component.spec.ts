import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { Exemple4Component } from './exemple4.component';

describe('Exemple4Component', () => {
  let component: Exemple4Component;
  let fixture: ComponentFixture<Exemple4Component>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ Exemple4Component ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(Exemple4Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
