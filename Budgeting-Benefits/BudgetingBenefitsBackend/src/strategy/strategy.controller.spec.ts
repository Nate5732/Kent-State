import { Test, TestingModule } from '@nestjs/testing';
import { StrategyController } from './strategy.controller';
import { StrategyService } from './strategy.service';

describe('StrategyController', () => {
  let controller: StrategyController;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      controllers: [StrategyController],
      providers: [StrategyService],
    }).compile();

    controller = module.get<StrategyController>(StrategyController);
  });

  it('should be defined', () => {
    expect(controller).toBeDefined();
  });
});
