import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { BestComponent } from './best.component';

describe('BestComponent', () => {
  let component: BestComponent;
  let fixture: ComponentFixture<BestComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ BestComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(BestComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
