import { TestBed } from '@angular/core/testing';

import { TrainingService } from './training.service';

describe('TrainingService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: TrainingService = TestBed.get(TrainingService);
    expect(service).toBeTruthy();
  });
});
