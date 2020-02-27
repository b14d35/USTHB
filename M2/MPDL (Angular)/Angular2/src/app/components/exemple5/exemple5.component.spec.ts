import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { Exemple5Component } from './exemple5.component';

describe('Exemple5Component', () => {
  let component: Exemple5Component;
  let fixture: ComponentFixture<Exemple5Component>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ Exemple5Component ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(Exemple5Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
